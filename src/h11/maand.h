// Created by Tiemen Molenaar in 2023
#pragma once
#ifndef MAAND_H
#define MAAND_H
namespace maand {
	enum Maand {
		ONBEKEND,
		JANUARI,
		FEBRUARI,
		MAART,
		APRIL,
		MEI,
		JUNI,
		JULI,
		AUGUSTUS,
		SEPTEMBER,
		OKTOBER,
		NOVEMBER,
		DECEMBER
	};

	const char* MAAND_NAAM[] = {
		"Onbekend",
		"Januari",
		"Februari",
		"Maart",
		"April",
		"Mei",
		"Juni",
		"Juli",
		"Augustus",
		"September",
		"Oktober",
		"November",
		"December"
	};
}
#endif