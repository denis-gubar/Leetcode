# Write your MySQL query statement below
SELECT Candidate.Name
  FROM Vote INNER JOIN Candidate
    ON Candidate.id = Vote.CandidateId
 GROUP BY Candidate.id, Candidate.Name 
 ORDER BY COUNT(*) DESC
 LIMIT 1