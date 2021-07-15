# Write your MySQL query statement below
SELECT person_name
  FROM
(SELECT person_name, lead(running_weight) OVER(ORDER BY turn) next_running_weight, running_weight FROM
(SELECT person_id, person_name, SUM(weight) OVER (ORDER BY turn) running_weight, turn
  FROM Queue) data) data
  WHERE running_weight <= 1000
    AND COALESCE(next_running_weight, 1001) > 1000