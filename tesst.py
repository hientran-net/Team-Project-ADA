def is_convex_polygon(points):
    n = len(points)
    if n < 3:
        return False
    def cross_product_sign(A, B, C):
        return (B[0] - A[0]) * (C[1] - A[1]) - (B[1] - A[1]) * (C[0] - A[0])
    cross_product_sign_initial = None

    for i in range(n):
        A = points[i]
        B = points[(i + 1) % n]
        C = points[(i + 2) % n]
        cross_product = cross_product_sign(A, B, C)

        if cross_product != 0: 
            current_sign = cross_product > 0

            if cross_product_sign_initial is None:
                cross_product_sign_initial = current_sign
            elif cross_product_sign_initial != current_sign:
                return False

    return True 

# Ví dụ kiểm tra
points = [(1, 3), (3, 6), (6, 7), (9, 6), (10, 3), (7, 1), (3, 4)]
print("Là đa giác lồi" if is_convex_polygon(points) else "Không phải là đa giác lồi")
