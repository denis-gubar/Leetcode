# Write your MySQL query statement below
SELECT title
  FROM Content
 WHERE Kids_content = 'Y'
   AND content_type = 'Movies'
   AND content_id IN (SELECT content_id
                        FROM TVProgram
					   WHERE MONTH(program_date) = 6
                         AND YEAR(program_date) = 2020);