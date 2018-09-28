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


#include <qlo/indexes/inflationindex.hpp>
#include <ql/indexes/inflationindex.hpp>


namespace QuantLibAddin {

	// "Zero" inflation index
	ZeroInflationIndex::ZeroInflationIndex(
		const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
		const std::string& familyName,
		const QuantLib::Region& region,
		bool revised,
		bool interpolated,
		QuantLib::Frequency& f,
		const QuantLib::Period& availabilityLag,
		const QuantLib::Currency& currency,
		const QuantLib::Handle<QuantLib::ZeroInflationTermStructure>& hZITS,
		bool permanent)
	: InflationIndex(properties, permanent) 
	{
		libraryObject_ = boost::shared_ptr<QuantLib::ZeroInflationIndex>(new
			QuantLib::ZeroInflationIndex(
				familyName, region, revised, interpolated, f, availabilityLag, currency, hZITS));
    }

	// "Year on Year" inflation 
    YoYInflationIndex::YoYInflationIndex(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
		const std::string& familyName,
		const QuantLib::Region& region,
		bool revised,
		bool interpolated,
		bool ratio, // is this one a genuine index or a ratio?
		QuantLib::Frequency& frequency,
		const QuantLib::Period& availabilityLag,
		const QuantLib::Currency& currency,
		const QuantLib::Handle<QuantLib::YoYInflationTermStructure>& hYoYITS,
		bool permanent)
	: InflationIndex(properties, permanent)
	{
		libraryObject_ = boost::shared_ptr<QuantLib::YoYInflationIndex>(new
			QuantLib::YoYInflationIndex(familyName, region, revised, interpolated,
				ratio, frequency, availabilityLag, currency, hYoYITS));
	}
	
}