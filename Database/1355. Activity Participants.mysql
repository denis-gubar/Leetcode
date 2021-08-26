# Write your MySQL query statement below
SELECT activity
  FROM
(SELECT activity,
       cnt,
       MAX(cnt) OVER () max_cnt,
       MIN(cnt) OVER () min_cnt
  FROM
(SELECT activity, count(Friends.id) cnt
  FROM Activities LEFT JOIN Friends
    ON (Activities.name = Friends.activity)
 GROUP BY activity) data) data
 WHERE cnt != max_cnt AND cnt != min_cnt   