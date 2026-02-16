CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
        SELECT salary 
        FROM (SELECT *, DENSE_RANK() OVER(ORDER BY salary DESC) AS 'rank' FROM Employee) t
        WHERE t.rank = N
        LIMIT 1
  );
END