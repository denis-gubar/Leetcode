# Write your MySQL query statement below
SELECT Data_Asc.id, Data_Asc.date, Data_Asc.people
  FROM (SELECT id, DATE, people, (@sa := CONCAT(SUBSTRING(@sa, 2), x)) AS x
          FROM (SELECT id, DATE, people, IF(people >= 100, '1', '0') as x
                  FROM stadium, (SELECT @sa := '000') as vars
                 ORDER BY id) AS Data) AS Data_Asc
 INNER JOIN (SELECT id, (@sd := CONCAT(SUBSTRING(@sd, 2), x)) AS x
               FROM (SELECT id, IF(people >= 100, '1', '0') as x
                       FROM stadium, (SELECT @sd := '000')  as vars
                      ORDER BY id DESC) AS Data) AS Data_Desc
    ON Data_Asc.id = Data_Desc.id
 WHERE instr(CONCAT(Data_Asc.x, REVERSE(Data_Desc.x)), '1111') > 0
 ORDER BY Data_Asc.id;