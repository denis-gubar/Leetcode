# Write your MySQL query statement below
SELECT AVG(Number) median
  FROM
(SELECT Number,
       COALESCE(LAG(F) OVER (ORDER BY Number), 0) + 1 P,
       F,
       a,
       b
  FROM       
(SELECT Number,
       SUM(Frequency) OVER (ORDER BY Number) F
  FROM Numbers) data CROSS JOIN
  (SELECT FLOOR((SUM(Frequency) + 1) / 2) a,
       FLOOR((SUM(Frequency) + 2) / 2) b
  FROM Numbers) x) Data
 WHERE a BETWEEN P AND F OR
       b BETWEEN P AND F