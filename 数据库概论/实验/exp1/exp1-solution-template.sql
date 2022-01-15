-- 姓名：陈南曈
-- 学号：191220008
-- 提交前请确保本次实验独立完成，若有参考请注明并致谢。

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q1
SELECT COUNT(id) AS speciesCount
FROM Species
WHERE description LIKE '%this%';
-- END Q1

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q2
SELECT Player.username, SUM(Phonemon.power) AS totalPhonemonPower
FROM Phonemon, Player
WHERE Phonemon.player=Player.id AND
      (Player.username='Cook' OR Player.username='Hughes')
GROUP BY Player.username;
-- END Q2

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q3
SELECT Team.title, COUNT(Player.id) AS numberOfPlayers
FROM Team, Player
WHERE Team.id=Player.team
GROUP BY Team.id
ORDER BY numberOfPlayers DESC;
-- END Q3

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q4
SELECT Species.id AS idSpecies, Species.title
FROM Species, Type
WHERE (Species.type1=Type.id AND Type.title='grass') OR
      (Species.type2=Type.id AND Type.title='grass');
-- END Q4

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q5
SELECT Player.id AS idPlayer, Player.username
FROM Player
WHERE Player.id NOT IN (
	SELECT Purchase.player
	FROM Purchase, Item
	WHERE Purchase.item=Item.id AND Item.type='F');
-- END Q5

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q6
SELECT Player.level, SUM(Item.price*Purchase.quantity) AS totalAmountSpentByAllPlayersAtLevel
FROM Item, Purchase, Player
WHERE Item.id=Purchase.item AND Purchase.player=Player.id
GROUP BY Player.level
ORDER BY totalAmountSpentByAllPlayersAtLevel DESC;
-- END Q6

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q7
SELECT Item.id AS item, Item.title, COUNT(*) AS numTimesPurchased
FROM Purchase, Item
WHERE Purchase.item=Item.id
GROUP BY Purchase.item
HAVING COUNT(*)>=ALL (
	SELECT COUNT(*)
	FROM Purchase
    GROUP BY Purchase.item);
-- END Q7

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q8
SELECT Player.id AS playerID, Player.username,
       (SELECT COUNT(DISTINCT Item.id)
		FROM Item, Purchase
	    WHERE Item.id=Purchase.item AND Item.type='F') AS numberDistinctFoodItemsPurchased
FROM Player
WHERE NOT EXISTS (
	  SELECT *
      FROM (SELECT DISTINCT Item.id
            FROM Item, Purchase
            WHERE Item.id=Purchase.item AND Item.type='F') Allfood
      WHERE NOT EXISTS (
		    SELECT *
            FROM Purchase
            WHERE Purchase.player=Player.id AND Purchase.item=Allfood.id));
-- END Q8

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q9
SELECT COUNT(*) AS numberOfPhonemonPairs, ROUND(SQRT(POWER(Pm1.latitude-Pm2.latitude,2)+POWER(Pm1.longitude-Pm2.longitude,2))*100, 2) AS distanceX
FROM Phonemon Pm1, Phonemon Pm2
WHERE Pm1.id < Pm2.id AND 
      ROUND(SQRT(POWER(Pm1.latitude-Pm2.latitude,2)+POWER(Pm1.longitude-Pm2.longitude,2))*100,2)<=ALL (
          SELECT ROUND(SQRT(POWER(Pm3.latitude-Pm4.latitude,2)+POWER(Pm3.longitude-Pm4.longitude,2))*100,2)
          FROM Phonemon Pm3, Phonemon Pm4
          WHERE Pm3.id < Pm4.id);
-- END Q9

-- ____________________________________________________________________________________________________________________________________________________________________________________________________________
-- BEGIN Q10
SELECT Player.username, Type.title AS typeTitle
FROM Player,
     Type,
	 (SELECT Type.id AS type, SUM(Species.id) AS speciesSum
	  FROM Type, Species
	  WHERE Type.id=Species.type1 OR Type.id=Species.type2
	  GROUP BY Type.id) typeSpeciesSum,
     (SELECT playerTypeSpecies.player, playerTypeSpecies.type, SUM(playerTypeSpecies.species) AS speciesSum
	  FROM 
		  ((SELECT Phonemon.player, Species.type1 AS type, Species.id AS species
		    FROM Phonemon, Species
		    WHERE Phonemon.species=Species.id AND Phonemon.player IS NOT NULL)
		    UNION
		   (SELECT Phonemon.player, Species.type2 AS type, Species.id AS species
		    FROM Phonemon, Species
		    WHERE Phonemon.species=Species.id AND Phonemon.player IS NOT NULL AND Species.type2 IS NOT NULL)) playerTypeSpecies
	  GROUP BY playerTypeSpecies.player, playerTypeSpecies.type) playerTypeSpeciesSum
WHERE typeSpeciesSum.type=playerTypeSpeciesSum.type AND
      typeSpeciesSum.speciesSum=playerTypeSpeciesSum.speciesSum AND
      Player.id=playerTypeSpeciesSum.player AND
      Type.id=typeSpeciesSum.type;
-- END Q10