/*
 Navicat Premium Data Transfer

 Source Server         : [DEV]fSahiN#9964
 Source Server Type    : MySQL
 Source Server Version : 50562
 Source Host           : 213.238.182.233:3306
 Source Schema         : web_core

 Target Server Type    : MySQL
 Target Server Version : 50562
 File Encoding         : 65001

 Date: 14/03/2022 16:02:40
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for svSettings
-- ----------------------------
DROP TABLE IF EXISTS `svSettings`;
CREATE TABLE `svSettings`  (
  `rdc_Kur` decimal(5, 2) NOT NULL DEFAULT 0.00
) ENGINE = MyISAM CHARACTER SET = utf8 COLLATE = utf8_turkish_ci ROW_FORMAT = Fixed;

-- ----------------------------
-- Records of svSettings
-- ----------------------------
INSERT INTO `svSettings` VALUES (10.00);

SET FOREIGN_KEY_CHECKS = 1;
