# Write your MySQL query statement below
SELECT e.name AS Name,
     b.bonus as Bonus
From Employee e
LEFT JOIN Bonus b 
ON e.empId = b.empId
WHERE b.bonus < 1000 OR b.bonus is NULL;