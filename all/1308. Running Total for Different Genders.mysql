# Write your MySQL query statement below
SELECT gender, 
       day, 
       (SELECT SUM(score_points) 
          FROM Scores Other
         WHERE Main.gender = Other.gender
           AND Main.day >= Other.day) total
  FROM Scores Main
 GROUP BY gender, day
 ORDER BY gender, day