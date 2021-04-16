-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: May 19, 2019 at 06:17 PM
-- Server version: 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `888aec`
--

-- --------------------------------------------------------

--
-- Table structure for table `consumer`
--

CREATE TABLE IF NOT EXISTS `consumer` (
  `CID` varchar(10) NOT NULL,
  `CName` varchar(30) DEFAULT NULL,
  `Address` varchar(100) DEFAULT NULL,
  `ContactNo` varchar(21) DEFAULT NULL,
  `email` varchar(30) DEFAULT NULL,
  `MID` varchar(10) DEFAULT NULL,
  `Password` varchar(10) DEFAULT NULL,
  PRIMARY KEY (`CID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `consumer`
--

INSERT INTO `consumer` (`CID`, `CName`, `Address`, `ContactNo`, `email`, `MID`, `Password`) VALUES
('C001', 'Arindam Das', 'Jalukbari', '7002309864', 'arindam@gmail.com', 'M001', '7002309864'),
('C002', 'Rajarshi Nath', 'Jalukbari', '7002870188', 'rn@gmail.com', 'M002', '7002870188'),
('C003', 'Bitupon Nath', 'Adabari', '666888666998', 'bitn@yahoo.com', 'M003', '6668886669'),
('C004', 'Sadab', 'Panbazar', '77868768787', 'sadab@gmail.com', 'M004', '7786876878');

-- --------------------------------------------------------

--
-- Table structure for table `datalog`
--

CREATE TABLE IF NOT EXISTS `datalog` (
  `SLID` int(10) NOT NULL AUTO_INCREMENT,
  `Dated` date DEFAULT NULL,
  `TimeStamp` varchar(20) DEFAULT NULL,
  `CID` varchar(10) DEFAULT NULL,
  `MID` varchar(10) DEFAULT NULL,
  `Unit` int(10) DEFAULT NULL,
  PRIMARY KEY (`SLID`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Dumping data for table `datalog`
--

INSERT INTO `datalog` (`SLID`, `Dated`, `TimeStamp`, `CID`, `MID`, `Unit`) VALUES
(1, '2019-04-24', '06:01:13 PM', 'C001', 'M001', 5),
(2, '2019-04-24', '06:01:19 PM', 'C001', 'M001', 6),
(3, '2019-04-24', '06:01:26 PM', 'C001', 'M001', 7),
(4, '2019-04-24', '06:04:21 PM', 'C001', 'M001', 9),
(5, '2019-04-24', '06:08:54 PM', 'C001', 'M001', 10),
(6, '2019-05-17', '04:45:50 PM', 'C001', 'M001', 1),
(7, '2019-05-17', '04:47:07 PM', 'C001', 'M001', 2),
(8, '2019-05-17', '04:48:27 PM', 'C001', 'M001', 3),
(9, '2019-05-17', '04:49:47 PM', 'C001', 'M001', 4);

-- --------------------------------------------------------

--
-- Table structure for table `meter`
--

CREATE TABLE IF NOT EXISTS `meter` (
  `MID` varchar(10) NOT NULL,
  `Capacity` varchar(10) DEFAULT NULL,
  `Unit` int(10) DEFAULT NULL,
  PRIMARY KEY (`MID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `meter`
--

INSERT INTO `meter` (`MID`, `Capacity`, `Unit`) VALUES
('M001', '1KV', 4),
('M002', '2KV', 0),
('M003', '3KV', 4),
('M004', '1KV', 0);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `UserID` varchar(20) NOT NULL,
  `Password` varchar(20) NOT NULL,
  PRIMARY KEY (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`UserID`, `Password`) VALUES
('admin', '1234'),
('u1', 'abcd');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
