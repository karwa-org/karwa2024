#!/usr/bin/env python3
import math

def convex_hull(points):
    def ccw(o, a, b):
        return (a[0] - o[0]) * (b[1] - o[1]) - (a[1] - o[1]) * (b[0] - o[0])

    # find lowestleftmost point
    lowest = points[0]
    for p in points:
        if p[1] < lowest[1] or (p[1] == lowest[1] and p[0] < lowest[0]):
            lowest = p

    # sort by polar angle
    points.sort(key=lambda p: math.atan2(p[1], p[0]))

    stack = []
    for p in points:
        while len(stack) >= 2 and ccw(stack[-2], stack[-1], p) <= 0:
            stack.pop()
        stack.append(p)

    return stack

def projection(point_to_project, point1, point2):
    x1, y1 = point1
    x2, y2 = point2
    xp, yp = point_to_project
    c = (x2 - x1) * xp + (y2 - y1) * yp
    det = (y2 - y1)**2 + (x2 - x1)**2
    if det == 0:
        x_inter = xp
        y_inter = yp
    else:
        x_inter = (x2 - x1) * c / det
        y_inter = (y2 - y1) * c / det

    if x2 - x1 == 0:
        return math.sqrt((x2 - x1)**2 + (y2 - y1)**2) * y_inter / (y2 - y1)
    return math.sqrt((x2 - x1)**2 + (y2 - y1)**2) * x_inter / (x2 - x1)

def directional_rectangle_hull(points, point1, point2):
    projections_on_line = list(map(lambda p : projection(p, point1, point2), points))
    ort_point1 = (point1[1], - point1[0])
    ort_point2 = (point2[1], - point2[0])
    projections_on_orthogonal = list(map(lambda p : projection(p, ort_point1, ort_point2), points))
    return (max(projections_on_line) - min(projections_on_line)) *\
           (max(projections_on_orthogonal) - min(projections_on_orthogonal))

def rectangle_hull(points):
    points = list(points)
    min_area = math.inf
    for i in range(len(points)):
        min_area = min(min_area, directional_rectangle_hull(points, points[i], points[(i+1)%len(points)]))
    return min_area

##############
### INPUTS ###
##############

# Number of points
n = int(input())

points = []
for _ in range(n):
    points.append(tuple(map(int, input().split())))
print(rectangle_hull(convex_hull(points)))
