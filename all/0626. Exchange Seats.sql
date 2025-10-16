# Write your MySQL query statement below

SELECT ROW_NUMBER() OVER (ORDER BY (FLOOR((id + 1) / 2) * 2 + id MOD 2)) id, student
  FROM seat
 ORDER BY 1