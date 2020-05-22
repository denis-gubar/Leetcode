# Write your MySQL query statement below
SELECT DISTINCT id,
       name
  FROM
(SELECT id,
       name,
       DATE_SUB(login_date, INTERVAL ROW_NUMBER() OVER (PARTITION BY id ORDER BY login_date) DAY) x
  FROM
(SELECT DISTINCT Accounts.id, 
       Accounts.name,
       Logins.login_date
  FROM Accounts INNER JOIN Logins
 USING (id)) data) data
 GROUP BY id, name, x
 HAVING COUNT(*) >= 5