# Write your MySQL query statement below
WITH data as
(SELECT America, Europe, Asia,
        CASE
          WHEN America IS NOT NULL THEN
             ROW_NUMBER() OVER (ORDER BY COALESCE(America, '~'))
        END America_Rank,
        CASE
          WHEN Europe IS NOT NULL THEN
             ROW_NUMBER() OVER (ORDER BY COALESCE(Europe, '~'))
        END Europe_Rank,
        CASE
          WHEN Asia IS NOT NULL THEN
             ROW_NUMBER() OVER (ORDER BY COALESCE(Asia, '~'))
        END Asia_Rank
  FROM
(SELECT CASE
          WHEN continent = 'America' THEN name
       END America,
       CASE
          WHEN continent = 'Europe' THEN name
       END Europe,
       CASE
          WHEN continent = 'Asia' THEN name
       END Asia
  FROM student) data),
Main as
(SELECT DISTINCT COALESCE(America_Rank, Europe_Rank, Asia_Rank) Main_Rank
   FROM data
)
SELECT Am_Data.America, As_Data.Asia, Eu_Data.Europe
  FROM Main LEFT JOIN data Am_Data
    ON Main.Main_Rank = Am_Data.America_Rank
  LEFT JOIN data Eu_Data
    ON Main.Main_Rank = Eu_Data.Europe_Rank
  LEFT JOIN data As_Data
    ON Main.Main_Rank = As_Data.Asia_Rank
 ORDER BY Main.Main_Rank
