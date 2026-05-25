WITH managers(managerId) AS (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(id) >= 5
)

SELECT name
FROM Employee
WHERE id IN (SELECT managerId FROM managers);