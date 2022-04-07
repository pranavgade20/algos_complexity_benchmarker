# https://jsfiddle.net/z51x9asg/show

import numpy as np
import pandas as pd
import plotly.graph_objects as go
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures


def main():
    sort_names = ['stack_reduced_quicksort', 'quicksort', 'merge_sort_with_insertion_sort']
    data = pd.read_csv('results.csv')
    data = data[data['type'].map(lambda x: x in sort_names)]
    data['type'] = data['type'].astype('category')
    arr = []
    for sort_name in data['type'].cat.categories:
        df = data[data['type'] == sort_name]
        X = df['size'].values.reshape(-1, 1)
        x_range = np.linspace(0, X.max(), 100).reshape(-1, 1)
        poly = PolynomialFeatures(2)
        poly.fit(X)
        X_poly = poly.transform(X)
        x_range_poly = poly.transform(x_range)

        model = LinearRegression(fit_intercept=False)
        model.fit(X_poly, df['runtime'])
        y_poly = model.predict(x_range_poly)
        markers = go.Scatter(mode='markers', x=df['size'], y=df['runtime'], opacity=0.5, name=sort_name)
        line = go.Scatter(x=x_range.squeeze(), y=y_poly, name=f'{sort_name} regression line', hoverinfo='skip',
                          line=go.scatter.Line(color=None))
        arr.append(markers)
        arr.append(line)

    fig = go.Figure(arr)
    fig.update_layout(
        title="Runtime of Sorting Algorithms",
        xaxis_title="Input Size (number of elements)",
        yaxis_title="Runtime (seconds)",
        legend_title_text='Algorithm'
    )
    fig.show()
    fig.write_html("plot.html")


if __name__ == '__main__':
    main()

# 2022-02-17_19-46