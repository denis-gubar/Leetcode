# Write your MySQL query statement below
SELECT A.id p1,
       B.id p2,
       abs((B.x_value - A.x_value) * (B.y_value - A.y_value)) area
  FROM Points A INNER JOIN Points B
    ON A.id < B.id
   AND abs((B.x_value - A.x_value) * (B.y_value - A.y_value)) > 0
 ORDER BY area DESC, p1, p2