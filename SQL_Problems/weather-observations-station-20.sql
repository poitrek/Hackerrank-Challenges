------ First accepted solution ------
SELECT ROUND(LAT_N, 4) FROM (
SELECT LAT_N,
    @rownum := @rownum + 1 AS RANK
    FROM (SELECT LAT_N FROM STATION ORDER BY LAT_N) AS T,
    (SELECT @rownum := 0) AS R
    ) AS P
    WHERE RANK = (SELECT (COUNT(*)+1)/2 FROM STATION)

------ Solution in SQL Server - only for odd table size
SELECT FORMAT(ROUND(LAT_N, 4), 'N4') FROM
(SELECT ROW_NUMBER() OVER (ORDER BY LAT_N) ROW_NUM, LAT_N FROM STATION) AS T
WHERE ROW_NUM = (SELECT (COUNT(*)+1)/2 FROM STATION);

------ Solution that should work for both odd/even table size ------
SELECT ROUND(AVG(S.LAT_N), 4) FROM STATION S WHERE
ABS((SELECT COUNT(*) FROM STATION WHERE LAT_N < S.LAT_N) -
(SELECT COUNT(*) FROM STATION WHERE LAT_N > S.LAT_N)) <= 1;