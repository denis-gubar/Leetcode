# Write your MySQL query statement below
WITH Data AS
(
SELECT COALESCE(SUM(
    CASE
       WHEN duration < 300 THEN 1
       ELSE 0
    END), 0) as "[0-5>",
     COALESCE(SUM(
    CASE
       WHEN duration >= 300 and duration < 600 THEN 1
       ELSE 0
    END), 0) as "[5-10>",
     COALESCE(SUM(
    CASE
       WHEN duration >= 600 and duration < 900 THEN 1
       ELSE 0
    END), 0) as "[10-15>",
     COALESCE(SUM(
    CASE
       WHEN duration >= 900 THEN 1
       ELSE 0
    END), 0) as "15 or more"
  FROM Sessions
)
select '[0-5>' as BIN, `[0-5>` as TOTAL from data
UNION ALL
select '[5-10>' as BIN, `[5-10>` as TOTAL from data
UNION ALL
select '[10-15>' as BIN, `[10-15>` as TOTAL from data
UNION ALL
select '15 or more' as BIN, `15 or more` as TOTAL from data
