/* Write your PL/SQL query statement below */
select id from weather curr
where temperature > (select oth.temperature from weather oth where curr.recorddate = oth.recorddate + 1)
