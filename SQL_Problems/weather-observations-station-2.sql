-- Select sum of northern latitudes and the sum of western longitudes from
-- all stations, rounded to 2 decimal points
SELECT ROUND(SUM(LAT_N), 2), ROUND(SUM(LONG_W), 2) FROM STATION