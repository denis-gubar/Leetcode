# Write your MySQL query statement below
SELECT data.Score,
       (SELECT COUNT(DISTINCT other.score)
          FROM Scores other
         WHERE other.score > data.score) + 1 AS Rank
  FROM Scores data
ORDER BY Rank;