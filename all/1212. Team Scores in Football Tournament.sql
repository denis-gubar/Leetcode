# Write your MySQL query statement below
SELECT Hosts.team_id, 
       Hosts.team_name,
       Hosts.num_points + Guests.num_points num_points
  FROM
(SELECT Teams.team_id, 
       Teams.team_name, 
       COALESCE(SUM(CASE
         WHEN Hosts.host_goals > Hosts.guest_goals THEN 3
         WHEN Hosts.host_goals < Hosts.guest_goals THEN 0
         WHEN Hosts.host_goals = Hosts.guest_goals THEN 1
       END), 0) num_points
  FROM Teams LEFT JOIN Matches Hosts
    ON Hosts.host_team = Teams.team_id
 GROUP BY Teams.team_id, Teams.team_name) Hosts INNER JOIN
(SELECT Teams.team_id, 
       COALESCE(SUM(CASE
         WHEN Guests.host_goals < Guests.guest_goals THEN 3
         WHEN Guests.host_goals > Guests.guest_goals THEN 0
         WHEN Guests.host_goals = Guests.guest_goals THEN 1
       END), 0) num_points
  FROM Teams LEFT JOIN Matches Guests
    ON Guests.guest_team = Teams.team_id
 GROUP BY Teams.team_id, Teams.team_name) Guests
   ON Hosts.team_id = Guests.team_id
  ORDER BY 3 DESC, 1

    
  
 
 