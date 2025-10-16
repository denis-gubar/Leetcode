# Write your MySQL query statement below
SELECT Expressions.left_operand,
       Expressions.operator,
       Expressions.right_operand,
       CASE
         WHEN operator = '=' THEN
             CASE WHEN L.value = R.value THEN 'true'
                ELSE 'false'
             END
         WHEN operator = '<' THEN
             CASE WHEN L.value < R.value THEN 'true'
                ELSE 'false'
             END
         WHEN operator = '>' THEN
             CASE WHEN L.value > R.value THEN 'true'
                ELSE 'false'
             END
       END value
  FROM Expressions INNER JOIN Variables L
    ON Expressions.left_operand = L.name
 INNER JOIN Variables R
    ON Expressions.right_operand = R.name