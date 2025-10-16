# Write your MySQL query statement below
SELECT id,
       CASE
         WHEN p_id IS NULL THEN 'Root'
         WHEN id IN (SELECT DISTINCT P_ID FROM tree) THEN 'Inner'
         ELSE 'Leaf'
       END Type
  FROM tree