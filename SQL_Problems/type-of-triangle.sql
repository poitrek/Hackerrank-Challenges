------ OKAY ------
SELECT CASE
    WHEN A + B <= C OR A + C <= B OR B + C <= A THEN 'Not A Triangle'
    WHEN A = B AND B = C THEN 'Equilateral'
    WHEN (A = B) + (B = C) + (C = A) = 1 THEN 'Isosceles'
    WHEN (A = B) + (B = C) + (C = A) = 0 THEN 'Scalene'
    END AS TriangleType
FROM TRIANGLES