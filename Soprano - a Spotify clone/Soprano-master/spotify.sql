-- phpMyAdmin SQL Dump
-- version 5.0.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 08, 2021 at 05:04 PM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.2.34

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `spotify`
--

DELIMITER $$
--
-- Procedures
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `logIn` (`emailId` VARCHAR(200), `pass` VARCHAR(32))  BEGIN    
    SELECT * 
    FROM users 
    WHERE email=emailId AND password=pass;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `albums`
--

CREATE TABLE `albums` (
  `id` int(11) NOT NULL,
  `title` varchar(250) NOT NULL,
  `artist` int(11) NOT NULL,
  `genre` int(11) NOT NULL,
  `artworkPath` varchar(500) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `albums`
--

INSERT INTO `albums` (`id`, `title`, `artist`, `genre`, `artworkPath`) VALUES
(6, 'Resonance', 8, 12, './assets/images/albumArtwork/Suma.jpg'),
(7, 'Amrutha', 7, 14, './assets/images/albumArtwork/Amrutha.jpeg'),
(8, 'Chiptune', 5, 9, './assets/images/albumArtwork/Chiptune.jpg'),
(9, 'Limerence', 5, 11, './assets/images/albumArtwork/limerence.jpg'),
(10, 'Kawa', 5, 11, './assets/images/albumArtwork/Kawa.jpg');

-- --------------------------------------------------------

--
-- Table structure for table `artists`
--

CREATE TABLE `artists` (
  `id` int(11) NOT NULL,
  `name` varchar(250) NOT NULL,
  `count` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `artists`
--

INSERT INTO `artists` (`id`, `name`, `count`) VALUES
(5, 'Harikrishna Kunnath', 6),
(7, 'Amrutha Bhat', 7),
(8, 'Sumavarsha', 10);

-- --------------------------------------------------------

--
-- Table structure for table `genres`
--

CREATE TABLE `genres` (
  `id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `genres`
--

INSERT INTO `genres` (`id`, `name`) VALUES
(9, 'Chiptune'),
(10, 'Devotional'),
(11, 'Indie'),
(12, 'Pop'),
(13, 'Alternative Rock'),
(14, 'Bollywood');

-- --------------------------------------------------------

--
-- Table structure for table `playlists`
--

CREATE TABLE `playlists` (
  `id` int(11) NOT NULL,
  `name` varchar(50) NOT NULL,
  `owner` varchar(50) NOT NULL,
  `dateCreated` datetime NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `playlists`
--

INSERT INTO `playlists` (`id`, `name`, `owner`, `dateCreated`) VALUES
(6, 'Playlist', 'Prachi.sabarad@gmail.com', '2021-01-08 00:00:00');

-- --------------------------------------------------------

--
-- Table structure for table `playlistsongs`
--

CREATE TABLE `playlistsongs` (
  `id` int(11) NOT NULL,
  `songId` int(11) NOT NULL,
  `playlistId` int(11) NOT NULL,
  `playlistOrder` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `playlistsongs`
--

INSERT INTO `playlistsongs` (`id`, `songId`, `playlistId`, `playlistOrder`) VALUES
(8, 20, 6, 0),
(9, 27, 6, 1);

-- --------------------------------------------------------

--
-- Table structure for table `songs`
--

CREATE TABLE `songs` (
  `id` int(11) NOT NULL,
  `title` varchar(250) NOT NULL,
  `artist` int(11) NOT NULL,
  `album` int(11) NOT NULL,
  `genre` int(11) NOT NULL,
  `duration` varchar(8) NOT NULL,
  `path` varchar(500) NOT NULL,
  `albumOrder` int(11) NOT NULL,
  `plays` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `songs`
--

INSERT INTO `songs` (`id`, `title`, `artist`, `album`, `genre`, `duration`, `path`, `albumOrder`, `plays`) VALUES
(20, 'All I Want', 8, 6, 12, '04:03', './assets/music/AllIWant.mp3', 1, 4),
(21, 'Dhadak', 7, 7, 14, '01:08', './assets/music/Dhadak.mp3', 1, 1),
(22, 'Eka Dantaya Dhimahi', 7, 7, 10, '00:36', './assets/music/EkadantayaDhimahi.mp3', 2, 1),
(23, 'i feel like i\'m sitting on a fancy fighter jet that\'s shooting bullets', 5, 8, 9, '01:29', './assets/music/fancyFighterJet.mp3', 1, 2),
(24, 'Ghar More Pardesiya', 7, 7, 14, '00:48', './assets/music/GharMorePardesiya.mp3', 3, 1),
(25, 'Jaan Nisaar', 7, 7, 14, '01:13', './assets/music/JaanNisaar.mp3', 4, 1),
(26, 'Kawa', 5, 10, 11, '02:02', './assets/music/Kawa.mp3', 1, 1),
(27, 'Limerence', 5, 9, 11, '03:22', './assets/music/Limerence.mp3', 1, 2),
(28, 'Maana Ke Hum Yaar Nahi', 7, 7, 14, '01:04', './assets/music/MaanaKeHumYaarNahi.mp3', 5, 1),
(29, 'Mad World', 8, 6, 12, '02:59', './assets/music/MadWorld.mp3', 2, 1),
(30, 'Make You Feel My Love', 8, 6, 12, '03:32', './assets/music/MakeYouFeelMyLove.mp3', 3, 1),
(31, '!similar', 5, 8, 9, '00:54', './assets/music/notSimilar.mp3', 2, 1),
(32, 'Raabta', 7, 7, 14, '01:14', './assets/music/Raabta.mp3', 6, 1),
(33, 'Tujhe Kitna Chahne Lage Hum', 7, 7, 14, '01:05', './assets/music/TujheKitnaChahneLageHum.mp3', 7, 1),
(34, 'Supermarket Flowers', 8, 6, 12, '03:36', './assets/music/SupermarketFlowers.mp3', 4, 1),
(35, 'The Scientist', 8, 6, 13, '05:11', './assets/music/TheScientist.mp3', 5, 1),
(36, 'Thousand Years', 8, 6, 12, '04:50', './assets/music/ThousandYears.mp3', 6, 1),
(37, 'You Are The Reason', 8, 6, 12, '03:41', './assets/music/YouAreTheReason.mp3', 7, 1);

--
-- Triggers `songs`
--
DELIMITER $$
CREATE TRIGGER `playCountUpdate` AFTER UPDATE ON `songs` FOR EACH ROW BEGIN
    UPDATE artists a
    SET count = (select sum(s.plays) from songs s
    WHERE a.id = s.artist
    GROUP BY s.artist);
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `firstName` varchar(50) NOT NULL,
  `lastName` varchar(50) NOT NULL,
  `email` varchar(200) NOT NULL,
  `password` varchar(32) NOT NULL,
  `signUpDate` datetime NOT NULL,
  `profilePic` varchar(500) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `firstName`, `lastName`, `email`, `password`, `signUpDate`, `profilePic`) VALUES
(9, 'Prachi', 'Sabarad', 'Prachi.sabarad@gmail.com', '5f4dcc3b5aa765d61d8327deb882cf99', '2021-01-08 00:00:00', 'assets/images/profile-pics/head_emerald.png');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `albums`
--
ALTER TABLE `albums`
  ADD PRIMARY KEY (`id`),
  ADD KEY `artistToAlbum` (`artist`),
  ADD KEY `genreToAlbum` (`genre`);

--
-- Indexes for table `artists`
--
ALTER TABLE `artists`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `genres`
--
ALTER TABLE `genres`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `playlists`
--
ALTER TABLE `playlists`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk` (`owner`);

--
-- Indexes for table `playlistsongs`
--
ALTER TABLE `playlistsongs`
  ADD PRIMARY KEY (`id`),
  ADD KEY `fk1` (`playlistId`),
  ADD KEY `fk2` (`songId`);

--
-- Indexes for table `songs`
--
ALTER TABLE `songs`
  ADD PRIMARY KEY (`id`),
  ADD KEY `artistToSong` (`artist`),
  ADD KEY `albumToSong` (`album`),
  ADD KEY `genreToSong` (`genre`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `email` (`email`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `albums`
--
ALTER TABLE `albums`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `artists`
--
ALTER TABLE `artists`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `genres`
--
ALTER TABLE `genres`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- AUTO_INCREMENT for table `playlists`
--
ALTER TABLE `playlists`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT for table `playlistsongs`
--
ALTER TABLE `playlistsongs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT for table `songs`
--
ALTER TABLE `songs`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=38;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `albums`
--
ALTER TABLE `albums`
  ADD CONSTRAINT `genreToAlbum` FOREIGN KEY (`genre`) REFERENCES `genres` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `playlists`
--
ALTER TABLE `playlists`
  ADD CONSTRAINT `fk` FOREIGN KEY (`owner`) REFERENCES `users` (`email`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `playlistsongs`
--
ALTER TABLE `playlistsongs`
  ADD CONSTRAINT `fk1` FOREIGN KEY (`playlistId`) REFERENCES `playlists` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `fk2` FOREIGN KEY (`songId`) REFERENCES `songs` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `songs`
--
ALTER TABLE `songs`
  ADD CONSTRAINT `albumToSong` FOREIGN KEY (`album`) REFERENCES `albums` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `artistToSong` FOREIGN KEY (`artist`) REFERENCES `artists` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `genreToSong` FOREIGN KEY (`genre`) REFERENCES `genres` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
