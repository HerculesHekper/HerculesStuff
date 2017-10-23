CREATE VIEW vw_nb_online AS
SELECT 
	COUNT(char_id) AS players_online 
FROM `char` 
WHERE `online` > 0;
