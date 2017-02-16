BEGIN TRANSACTION;

DROP TABLE IF EXISTS [Items];
DROP TABLE IF EXISTS [Inventory];
DROP TABLE IF EXISTS [test];

CREATE TABLE [test]
(
    n INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
    a TEXT
);
INSERT INTO test VALUES(1, 'a');
INSERT INTO test VALUES(2, 'b');
INSERT INTO test VALUES(null, 'e');

CREATE TABLE [Items]
(      [ItemID] INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
       [Name] TEXT,
       [Count] INTEGER,
       [Type] INTEGER,
       [ImagePath] TEXT
);

CREATE TABLE [Inventory]
(
   [ItemID] INTEGER NOT NULL,
   [X] INTEGER NOT NULL,
   [Y] INTEGER NOT NULL,

   PRIMARY KEY ("X","Y"),
   FOREIGN KEY ([ItemID]) REFERENCES [Items] ([ItemID]) 
		ON DELETE NO ACTION ON UPDATE NO ACTION
);

INSERT INTO Items VALUES(null,'apple',1,0,'./apple.jpg');
INSERT INTO Items VALUES(null,'apple',2,0,'./apple.jpg');
INSERT INTO Inventory VALUES(1, 0, 0);
INSERT INTO Inventory VALUES(2, 1, 1);

--select X, Y, Count, ImagePath from Inventory inner join Items where Inventory.ItemID = Items.ItemID
COMMIT;
