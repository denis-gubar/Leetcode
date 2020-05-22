# Write your MySQL query statement below
SELECT DISTINCT Likes.page_id recommended_page
  FROM Friendship INNER JOIN Likes
    ON Friendship.user1_id = 1 AND Friendship.user2_id = Likes.user_id 
    OR Friendship.user2_id = 1 AND Friendship.user1_id = Likes.user_id
 WHERE Likes.page_id NOT IN
  (SELECT page_id from Likes WHERE user_id = 1)