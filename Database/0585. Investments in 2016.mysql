# Write your MySQL query statement below
SELECT SUM(Main.TIV_2016) TIV_2016
  FROM insurance Main
 WHERE EXISTS (SELECT NULL FROM insurance Other 
                WHERE Main.TIV_2015 = Other.TIV_2015
                  AND Main.PID != Other.PID)
   AND NOT EXISTS (SELECT NULL FROM insurance Other
                    WHERE Main.PID != Other.PID
                      AND Main.LAT = Other.LAT 
                      AND Main.LON = Other.LON)
             
  