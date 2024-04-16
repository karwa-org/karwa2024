#!/usr/bin/env python3
import math

def convex_hull_2(points):
    def vector(p1, p2):
        return (p2[0] - p1[0], p2[1] - p1[1])
    def dot_product(vect1, vect2):
        return vect1[0] * vect2[0] + vect1[1] * vect2[1]
    def norm(vect):
        return math.sqrt(vect[0]**2 + vect[1]**2)

    rightmost_point = points[0]
    for p in points:
        if p[0] > rightmost_point[0]:
            rightmost_point = p
    stack = []

    new_point = rightmost_point
    cosine = None
    while new_point not in stack:
        stack.append(new_point)
        new_point = None
        cosine = 1
        for test_p in points:
            if test_p != stack[-1]:
                fixed_p = stack[-2] if len(stack) >= 2 else (stack[-1][0], stack[-1][1] - 1)
                v1 = vector(stack[-1], fixed_p)
                v2 = vector(stack[-1], test_p)
                test_cosine = dot_product(v1, v2) / (norm(v1) * norm(v2))
                if test_cosine < cosine:
                    cosine = test_cosine
                    new_point = test_p

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
    min_area = math.inf
    for i in range(len(points)):
        current_area = directional_rectangle_hull(points, points[i], points[(i+1)%len(points)])
        min_area = min(min_area, current_area)
    return min_area

##############
### INPUTS ###
##############

# Number of points
n = int(input())

points = []
for _ in range(n):
    points.append(tuple(map(int, input().split())))

print(rectangle_hull(convex_hull_2(points)))
