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

#if defined(HAVE_CONFIG_H)
#include <qlo/config.hpp>
#endif

#include <qlo/indexes/inflationindexSpecific.hpp>

#include <ql/utilities/dataparsers.hpp>

//#include <boost/algorithm/string/case_conv.hpp>
//using boost::algorithm::to_upper_copy;
using ObjectHandler::ValueObject;
using boost::shared_ptr;

namespace QuantLibAddin {

	//! AU CPI index (either quarterly or annual)
	AUCPI::AUCPI(const shared_ptr<ObjectHandler::ValueObject>& properties,
		QuantLib::Frequency &frequency,
		bool &revised,
		bool &interpolated,
		const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
		bool permanent) : ZeroInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::ZeroInflationIndex>(new
			QuantLib::AUCPI(frequency, revised, interpolated, ts));
	}

	//! Genuine year-on-year AU CPI (i.e. not a ratio of AU CPI)
	YYAUCPI::YYAUCPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
		QuantLib::Frequency &frequency,
		bool &revised,
		bool &interpolated,
		const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
		bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYAUCPI(frequency, revised, interpolated, ts));
	}

	//! Fake year-on-year AU CPI (i.e. a ratio of AU CPI)
	YYAUCPIr::YYAUCPIr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
		QuantLib::Frequency &frequency,
		bool &revised,
		bool &interpolated,
		const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
		bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYAUCPIr(frequency, revised, interpolated, ts));
	}


	//! EU HICP index
	EUHICP::EUHICP(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent) : ZeroInflationIndex(properties, permanent)
		{
			libraryObject_ = shared_ptr<QuantLib::ZeroInflationIndex>(new
				QuantLib::EUHICP(interpolated, ts));
		}

	//! EU HICPXT index
	EUHICPXT::EUHICPXT(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent) : ZeroInflationIndex(properties, permanent)
		{
			libraryObject_ = shared_ptr<QuantLib::ZeroInflationIndex>(new
				QuantLib::EUHICPXT(interpolated, ts));
		}

	//! Genuine year-on-year EU HICP (i.e. not a ratio of EU HICP)
	YYEUHICP::YYEUHICP(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent) : YoYInflationIndex(properties, permanent)
		{
			libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
				QuantLib::YYEUHICP(interpolated, ts));
		}

	//! Genuine year-on-year EU HICPXT
	YYEUHICPXT::YYEUHICPXT(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYEUHICPXT(interpolated, ts));
	}

	//! Fake year-on-year EU HICP (i.e. a ratio of EU HICP)
	YYEUHICPr::YYEUHICPr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYEUHICPr(interpolated, ts));
	}


	//! FR HICP index
	FRHICP::FRHICP(const shared_ptr<ObjectHandler::ValueObject>& properties,
		bool &interpolated,
		const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
		bool permanent) : ZeroInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::ZeroInflationIndex>(new
			QuantLib::FRHICP(interpolated, ts));
	}

	//! Genuine year-on-year FR HICP (i.e. not a ratio)
	YYFRHICP::YYFRHICP(const shared_ptr<ObjectHandler::ValueObject>& properties,
		bool &interpolated,
		const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
		bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYFRHICP(interpolated, ts));
	}

	//! Fake year-on-year FR HICP (i.e. a ratio)
	YYFRHICPr::YYFRHICPr(const shared_ptr<ObjectHandler::ValueObject>& properties,
		bool &interpolated,
		const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
		bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYFRHICPr(interpolated, ts));
	}


	//! UK Retail Price Inflation Index
	UKRPI::UKRPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent) : ZeroInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::ZeroInflationIndex>(new
			QuantLib::UKRPI(interpolated, ts));
	}

	//! Genuine year-on-year UK RPI (i.e. not a ratio of UK RPI)
	YYUKRPI::YYUKRPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYUKRPI(interpolated, ts));
	}

	//! Fake year-on-year UK RPI (i.e. a ratio of UK RPI)
	YYUKRPIr::YYUKRPIr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYUKRPIr(interpolated, ts));
	}


	//! US CPI index
	USCPI::USCPI(const shared_ptr<ObjectHandler::ValueObject>& properties,
		bool &interpolated,
		const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
		bool permanent)	: ZeroInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::ZeroInflationIndex>(new
			QuantLib::USCPI(interpolated, ts));
	}

	//! Genuine year-on-year US CPI (i.e. not a ratio of US CPI)
	YYUSCPI::YYUSCPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYUSCPI(interpolated, ts));
	}

	//! Fake year-on-year US CPI (i.e. a ratio of US CPI)
	YYUSCPIr::YYUSCPIr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
		bool &interpolated,
		const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
		bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYUSCPI(interpolated, ts));
	}


	//! South African Comsumer Price Inflation Index
	ZACPI::ZACPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& ts,
			bool permanent) : ZeroInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::ZeroInflationIndex>(new
			QuantLib::USCPI(interpolated, ts));
	}

	//! Genuine year-on-year South African CPI (i.e. not a ratio of ZA CPI)
	YYZACPI::YYZACPI(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYZACPI(interpolated, ts));
	}

	//! Fake year-on-year South African CPI (i.e. a ratio of ZA CPI)
	YYZACPIr::YYZACPIr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			bool &interpolated,
			const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& ts,
			bool permanent) : YoYInflationIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YYZACPIr(interpolated, ts));
	}
}
