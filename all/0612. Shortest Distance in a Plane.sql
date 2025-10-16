# Write your MySQL query statement below
SELECT MIN(ROUND(sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)), 2)) shortest
  FROM point_2d A INNER JOIN point_2d B
    ON A.x != B.x OR A.y != B.y