# Write your MySQL query statement below
SELECT country_name,
       CASE 
         WHEN AVG(weather_state) <= 15 THEN 'Cold'
         WHEN AVG(weather_state) >= 25 THEN 'Hot'
         ELSE 'Warm'
       END weather_type
  FROM Countries INNER JOIN Weather
 USING (country_id)
  WHERE day BETWEEN '2019-11-01' AND '2019-11-30'
 GROUP BY Weather.country_id, country_name