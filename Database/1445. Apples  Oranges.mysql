# Write your MySQL query statement below
SELECT apples.sale_date, apples.sold_num - oranges.sold_num diff
  FROM Sales apples INNER JOIN Sales oranges
 USING (sale_date)
 WHERE apples.fruit = 'apples'
   AND oranges.fruit = 'oranges'