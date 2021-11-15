import matplotlib.pyplot as plt
from matplotlib import style

style.use("ggplot")
import numpy as np

X = np.array([[3.5, 9.1], [6.1, 5.5], [13.5, 8.6], [1, 1]])
colors = 10 * ["g", "r", "c", "k", "b"]


class KMean:
    def __init__(self, k, tot=0.001, max_iter=300):
        self.k = k
        self.tol = tot
        self.max_iter = max_iter

    def accum(self, data):
        self.mean_points = {}
        for i in range(self.k):
            self.mean_points[i] = data[i]
        for i in range(self.max_iter):
            self.classifications = {}
            for i in range(self.k):
                self.classifications[i] = []
            for featureset in data:
                distances = [
                    np.linalg.norm(featureset - self.mean_points[centroid])
                    for centroid in self.mean_points
                ]
                classification = distances.index(min(distances))
                self.classifications[classification].append(featureset)
            prev_mean_points = dict(self.mean_points)
            for classification in self.classifications:
                self.mean_points[classification] = np.average(
                    self.classifications[classification], axis=0
                )
                optimized = True
            for c in self.mean_points:
                original_centroid = prev_mean_points[c]
                current_centroid = self.mean_points[c]
                if (
                    np.sum(
                        (current_centroid - original_centroid)
                        / original_centroid
                        * 100.0
                    )
                    > self.tol
                ):
                    print(
                        np.sum(
                            (current_centroid - original_centroid) / original_centroid
                        )
                    )
                    optimized = False
            if optimized:
                break


clf = KMean(k=2)
clf.accum(X)

for centroid in clf.mean_points:
    plt.scatter(
        clf.mean_points[centroid][0],
        clf.mean_points[centroid][1],
        marker="o",
        color="k",
        s=150,
        linewidths=5,
    )

for cffn in clf.classifications:
    color = colors[cffn]
    for ftst in clf.classifications[cffn]:
        plt.scatter(
            ftst[0], ftst[1], marker="o", color=colors[cffn % 5], s=150, linewidths=5
        )

plt.show()
plt.clf()


clf = KMean(k=3)
clf.accum(X)

for centroid in clf.mean_points:
    plt.scatter(
        clf.mean_points[centroid][0],
        clf.mean_points[centroid][1],
        marker="o",
        color="k",
        s=150,
        linewidths=5,
    )

for cffn in clf.classifications:
    color = colors[cffn]
    for ftst in clf.classifications[cffn]:
        plt.scatter(
            ftst[0], ftst[1], marker="o", color=colors[cffn % 5], s=150, linewidths=5
        )

plt.show()
plt.clf()


clf = KMean(k=4)
clf.accum(X)

for centroid in clf.mean_points:
    plt.scatter(
        clf.mean_points[centroid][0],
        clf.mean_points[centroid][1],
        marker="o",
        color="k",
        s=150,
        linewidths=5,
    )

for cffn in clf.classifications:
    color = colors[cffn]
    for ftst in clf.classifications[cffn]:
        plt.scatter(
            ftst[0], ftst[1], marker="x", color=colors[cffn % 5], s=150, linewidths=5
        )

plt.show()
plt.clf()