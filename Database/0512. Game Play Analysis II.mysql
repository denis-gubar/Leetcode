# Write your MySQL query statement below
select player_id, 
cast(
    substr(date_device_id, instr(date_device_id, '#') + 1)
    as UNSIGNED) as device_id from
(
select player_id, MIN(CONCAT(DATE_FORMAT(event_date, '%Y%m%d'), '#', device_id))  as date_device_id from Activity
group by player_id
) as a;