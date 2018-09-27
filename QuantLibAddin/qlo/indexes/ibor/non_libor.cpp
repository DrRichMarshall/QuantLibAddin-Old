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

#include <qlo/indexes/ibor/non_libor.hpp>

#include <ql/utilities/dataparsers.hpp>

#include <boost/algorithm/string/case_conv.hpp>
using boost::algorithm::to_upper_copy;
using ObjectHandler::ValueObject;
using boost::shared_ptr;

namespace QuantLibAddin {

	// overnight idexes at the bottom, non-ois at the top
	// New Zealand Bills index - "Bkbm FRA"
	Bkbm::Bkbm(const shared_ptr<ValueObject>& properties,
                 const std::string& p,
                 const QuantLib::Handle<QuantLib::YieldTermStructure>& h,
                 bool permanent) : IborIndex(properties, permanent)
    {
		QuantLib::Period pp = QuantLib::PeriodParser::parse(p);
		pp.normalize();
		libraryObject_ = shared_ptr<QuantLib::IborIndex>(new
			QuantLib::Bkbm(pp, h));
    }

	// Canadian Bills (Bankers Acceptance) index - Canadian dollar offered rate Bills index / CDOR
	Cdor::Cdor(const shared_ptr<ValueObject>& properties,
		const std::string& p,
		const QuantLib::Handle<QuantLib::YieldTermStructure>& h,
		bool permanent) : IborIndex(properties, permanent)
	{
		QuantLib::Period pp = QuantLib::PeriodParser::parse(p);
		pp.normalize();
		libraryObject_ = shared_ptr<QuantLib::IborIndex>(new
			QuantLib::Cdor(pp, h));
	}

	// Australian Bills index - "bbsw"
	Bbsw::Bbsw(const shared_ptr<ValueObject>& properties,
		const std::string& p,
		const QuantLib::Handle<QuantLib::YieldTermStructure>& h,
		bool permanent) : IborIndex(properties, permanent)
	{
		QuantLib::Period pp = QuantLib::PeriodParser::parse(p);
		pp.normalize();
		libraryObject_ = shared_ptr<QuantLib::IborIndex>(new
			QuantLib::Bbsw(pp, h));
	}

	// Jpanaese Yen Tibor index - libor like, domestic a/365 index - "Yen Tibor" 
	// NOT EuroYen Tibor - which uses a/360 day count
	Tibor::Tibor(const shared_ptr<ValueObject>& properties,
		const std::string& p,
		const QuantLib::Handle<QuantLib::YieldTermStructure>& h,
		bool permanent) : IborIndex(properties, permanent)
	{
		QuantLib::Period pp = QuantLib::PeriodParser::parse(p);
		pp.normalize();
		libraryObject_ = shared_ptr<QuantLib::IborIndex>(new
			QuantLib::Tibor(pp, h));
	}


	// overnight indexes
	// USD - Federal Funds overnight index
	FedFunds::FedFunds(const shared_ptr<ValueObject>& properties,
		const QuantLib::Handle<QuantLib::YieldTermStructure>& h,
		bool permanent)
		: OvernightIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::FedFunds>(new QuantLib::FedFunds(h));
	}

	// NZD - Offical Cash Rate index - OCR
	Nzocr::Nzocr(const shared_ptr<ValueObject>& properties,
		const QuantLib::Handle<QuantLib::YieldTermStructure>& h,
		bool permanent)
		: OvernightIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::Nzocr>(new QuantLib::Nzocr(h));
	}

	// AUD - Offical Cash Rate index - OCR
	// It's called Aonia at the clearing house (LCH), a much better name would be AuOcr 
	Aonia::Aonia(const shared_ptr<ValueObject>& properties,
		const QuantLib::Handle<QuantLib::YieldTermStructure>& h,
		bool permanent)
		: OvernightIndex(properties, permanent)
	{
		libraryObject_ = shared_ptr<QuantLib::Aonia>(new QuantLib::Aonia(h));
	}

}
