import os
import threading
from timeit import timeit

import numpy as np
import pandas as pd
import tqdm


def main():
    df = pd.DataFrame(columns=['type', 'size', 'runtime'])
    df_lock = threading.Lock()
    sort_names = ['radixsort', 'bucketsort', 'countingsort']
    COUNT = 180
    for sort_name in sort_names:
        def fill_df(pos):
            rands = np.random.randint(5000, 100000, COUNT)
            res = []
            tbar = tqdm.tqdm(total=COUNT, position=pos)
            for r in rands:
                time = timeit(
                    stmt=f'subprocess.call(["cmake-build-debug/{sort_name}", '
                         f'*"{" ".join(str (x) for x in np.random.randint(-2147483648, 2147483647, size=r))}"'
                         f'.split(" ")], stdout=subprocess.DEVNULL)',
                    setup='import subprocess',
                    number=1)
                res.append((r, time))
                tbar.update(1)
            with df_lock:
                nonlocal df
                df = df.append(pd.DataFrame({'type': [sort_name for _ in range(COUNT)], 'size': [x[0] for x in res], 'runtime': [x[1] for x in res]}), ignore_index=True)

        threads = []
        for i in range(os.cpu_count()):
            th = threading.Thread(target=fill_df, args=(i,))
            th.start()
            threads.append(th)

        for t in threads:
            t.join()

        with df_lock:
            results = pd.read_csv('results.csv') if os.path.isfile('results.csv') else pd.DataFrame(columns=['type', 'size', 'runtime'])
            results = results.append(df)
            results.to_csv('results.csv', index=False)


if __name__ == '__main__':
    main()
