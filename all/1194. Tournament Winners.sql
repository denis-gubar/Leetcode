# Write your MySQL query statement below
SELECT group_id,
       player_id
  FROM
(SELECT group_id,
       player_id,
       ROW_NUMBER() OVER (PARTITION BY group_id ORDER BY score DESC, player_id) is_first_record
  FROM
(SELECT Players.group_id, Players.player_id,
COALESCE(SUM(CASE
  WHEN Players.player_id = Matches.first_player THEN first_score
  WHEN Players.player_id = Matches.second_player THEN second_score
END), 0) score
  FROM Players LEFT JOIN Matches
    ON Players.player_id = Matches.first_player
    OR Players.player_id = Matches.second_player
GROUP BY Players.group_id, Players.player_id) data) data
 WHERE is_first_record = 1