# Write your MySQL query statement below
SELECT Queries.id, Queries.year, COALESCE(NPV.npv, 0) npv
  FROM Queries LEFT JOIN NPV
  USING(id, year)