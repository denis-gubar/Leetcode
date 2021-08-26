# Write your MySQL query statement below
SELECT Results
  FROM
(SELECT Results,
       RANK() OVER (ORDER BY cnt desc, Results) is_first_record
   FROM       
(SELECT Users.name Results,
       Users.user_id,
       COUNT(DISTINCT movie_id) cnt
  FROM Users INNER JOIN Movie_Rating
 USING (user_id)
 GROUP BY Users.user_id, Users.name) data) data
 WHERE is_first_record = 1
UNION ALL 
SELECT Results
  FROM
(SELECT Results,
       RANK() OVER (ORDER BY rating desc, Results) is_first_record
   FROM       
(SELECT Movies.title Results,
       Movies.movie_id,
       AVG(Movie_Rating.rating) rating
  FROM Movies INNER JOIN Movie_Rating
 USING (movie_id)
 WHERE Movie_Rating.created_at BETWEEN '2020-02-01' AND '2020-02-29'
 GROUP BY Movies.movie_id, Movies.title) data) data
 WHERE is_first_record = 1