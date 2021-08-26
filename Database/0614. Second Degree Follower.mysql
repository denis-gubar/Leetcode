# Write your MySQL query statement below
SELECT Main.follower, COUNT(DISTINCT Other.follower) num
  FROM follow Main INNER JOIN follow Other
    ON Other.followee = Main.follower
 GROUP BY Main.follower
 ORDER BY 1