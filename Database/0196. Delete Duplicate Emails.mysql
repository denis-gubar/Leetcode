# Write your MySQL query statement below
delete from person
      where id in
      (select id from
          (select curr.id from person as curr inner join person as oth 
           on curr.email = oth.email and curr.id > oth.id
          ) as x
      );