# Write your MySQL query statement below
SELECT DISTINCT Num as ConsecutiveNums 
  FROM (SELECT @prev2 AS Prev_Num2,
               (@prev2 := @prev) AS Prev_Num,
               (@prev := Data.Num) AS Num
          FROM (SELECT Data.Id, Data.Num
                  FROM (SELECT Logs.Id, Logs.Num
                          FROM Logs,
                               (SELECT @prev := NULL, @prev2 := NULL) AS vars
                         ORDER BY Logs.Id) AS Data) AS Data) AS Data
 WHERE Num = Prev_Num
   AND Num = Prev_Num2;
