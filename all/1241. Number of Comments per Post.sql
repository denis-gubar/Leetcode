# Write your MySQL query statement below
SELECT Posts.sub_id post_id, COUNT(DISTINCT Comments.sub_id) number_of_comments
  FROM
(SELECT DISTINCT sub_id
  FROM Submissions
 WHERE parent_id IS NULL) Posts LEFT JOIN Submissions Comments
    ON Posts.sub_id = Comments.parent_id
 GROUP BY Posts.sub_id