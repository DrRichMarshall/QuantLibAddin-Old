/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2018 Richard Marshall

This file is part of QuantLib, a free-software/open-source library
for financial quantitative analysts and developers - http://quantlib.org/

QuantLib is free software: you can redistribute it and/or modify it
under the terms of the QuantLib license.  You should have received a
copy of the license along with this program; if not, please email
<quantlib-dev@lists.sf.net>. The license is also available online at
<http://quantlib.org/license.shtml>.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file inflationindexSpecific.hpp
	\brief base classes for specific implementations of inflation indexes in Alphabetical order
*/

#ifndef qla_inflation_index_specific_hpp
#define qla_inflation_index_specific_hpp

#include <qlo/indexes/inflationindex.hpp>

//#include <ql/indexes/inflationindex.hpp>

#include <ql/indexes/inflation/aucpi.hpp>
#include <ql/indexes/inflation/euhicp.hpp>
#include <ql/indexes/inflation/frhicp.hpp>
#include <ql/indexes/inflation/ukrpi.hpp>
#include <ql/indexes/inflation/uscpi.hpp>
#include <ql/indexes/inflation/zacpi.hpp>


namespace QuantLibAddin {

	//! AU CPI index (either quarterly or annual)
	class AUCPI : public ZeroInflationIndex {
	public:
		AUCPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			QuantLib::Frequency &frequency,
			bool &revised,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent);
	};

	//! Genuine year-on-year AU CPI (i.e. not a ratio of AU CPI)
	class YYAUCPI : public YoYInflationIndex {
	public:
		YYAUCPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			QuantLib::Frequency &frequency,
			bool &revised,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};

	//! Fake year-on-year AU CPI (i.e. a ratio of AU CPI)
	class YYAUCPIr : public YoYInflationIndex {
	public:
		YYAUCPIr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			QuantLib::Frequency &frequency,
			bool &revised,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};


	//! EU HICP index
	class EUHICP : public ZeroInflationIndex {
	public:
		EUHICP(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent);
	};

	//! EU HICPXT index
	class EUHICPXT : public ZeroInflationIndex {
	public:
		EUHICPXT(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent);
	};

	//! Genuine year-on-year EU HICP (i.e. not a ratio of EU HICP)
	class YYEUHICP : public YoYInflationIndex {
	public:
		YYEUHICP(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};

	//! Genuine year-on-year EU HICPXT
	class YYEUHICPXT : public YoYInflationIndex {
	public:
		YYEUHICPXT(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};

	//! Fake year-on-year EU HICP (i.e. a ratio of EU HICP)
	class YYEUHICPr : public YoYInflationIndex {
	public:
		YYEUHICPr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};


	//! FR HICP index
	class FRHICP : public ZeroInflationIndex {
	public:
		FRHICP(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent);
	};

	//! Genuine year-on-year FR HICP (i.e. not a ratio)
	class YYFRHICP : public YoYInflationIndex {
	public:
		YYFRHICP(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};

	//! Fake year-on-year FR HICP (i.e. a ratio)
	class YYFRHICPr : public YoYInflationIndex {
	public:
		YYFRHICPr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};


	//! UK Retail Price Inflation Index
	class UKRPI : public ZeroInflationIndex {
	public:
		UKRPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties, 
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent);
	};

	//! Genuine year-on-year UK RPI (i.e. not a ratio of UK RPI)
	class YYUKRPI : public YoYInflationIndex {
	public:
		YYUKRPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};

	//! Fake year-on-year UK RPI (i.e. a ratio of UK RPI)
	class YYUKRPIr : public YoYInflationIndex {
	public:
		YYUKRPIr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};


	//! US CPI index
	class USCPI : public ZeroInflationIndex {
	public:
		USCPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties, 
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent);
	};

	//! Genuine year-on-year US CPI (i.e. not a ratio of US CPI)
	class YYUSCPI : public YoYInflationIndex {
	public:
		YYUSCPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties, 
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};

	//! Fake year-on-year US CPI (i.e. a ratio of US CPI)
	class YYUSCPIr : public YoYInflationIndex {
	public:
		YYUSCPIr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};


	//! South African Comsumer Price Inflation Index
	class ZACPI : public ZeroInflationIndex {
	public:
		ZACPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent);
	};

	//! Genuine year-on-year South African CPI (i.e. not a ratio of ZA CPI)
	class YYZACPI : public YoYInflationIndex {
	public:
		YYZACPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};

	//! Fake year-on-year South African CPI (i.e. a ratio of ZA CPI)
	class YYZACPIr : public YoYInflationIndex {
	public:
		YYZACPIr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent);
	};
}

#endif
