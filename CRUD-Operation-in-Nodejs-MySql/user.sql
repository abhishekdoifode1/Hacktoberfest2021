-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 06, 2021 at 09:47 AM
-- Server version: 10.4.19-MariaDB
-- PHP Version: 8.0.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `user`
--

-- --------------------------------------------------------

--
-- Table structure for table `user_data`
--

CREATE TABLE `user_data` (
  `id` int(10) UNSIGNED NOT NULL,
  `name` varchar(255) NOT NULL,
  `gender` varchar(15) DEFAULT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(50) NOT NULL,
  `picpath` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `user_data`
--

INSERT INTO `user_data` (`id`, `name`, `gender`, `email`, `password`, `picpath`) VALUES
(1, 'Raj Gohil\'s', 'male', 'rajgohil07@gmail.com', '\'s\'sss\'s\'s\'s\'', NULL),
(2, 'gopi rathod', 'female', 'gopirathod@gmail.com', '', NULL),
(3, 'mahesh bhatt', 'male', 'mahesh@gmail.com', '', NULL),
(4, 'suresh chav', 'male', 'suresh@gmail.com', '', NULL),
(5, 'trupti shah', 'female', 'truptishah@gmail.com', '', NULL),
(6, 'khyati thakkar', 'female', 'khyatithakkar@gmail.com', '', NULL),
(7, 'mansi rao', 'female', 'mansi@gmail.com', '', NULL),
(8, 'monilpatel', 'male', 'monilpatel@gmail.com', '', NULL),
(9, 'nandini', 'female', 'nandini@gmail.com', '', NULL);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `user_data`
--
ALTER TABLE `user_data`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY `email` (`email`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `user_data`
--
ALTER TABLE `user_data`
  MODIFY `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
