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

#ifndef qla_non_libor_hpp
#define qla_non_libor_hpp

#include <qlo/indexes/iborindex.hpp>
#include <ql/indexes/ibor/bkbm.hpp>
#include <ql/indexes/ibor/cdor.hpp>
#include <ql/indexes/ibor/bbsw.hpp>
#include <ql/indexes/ibor/tibor.hpp>
#include <ql/indexes/ibor/fedfunds.hpp>
#include <ql/indexes/ibor/nzocr.hpp>
#include <ql/indexes/ibor/aonia.hpp>


namespace QuantLibAddin {

	// overnight idexes at the bottom, non-ois at the top
	// NZD - New Zealand Bills index - "Bkbm FRA"
	// As of 2018, active benchmarks = 1m, 2m, 3m, 4m, 5m, 6m
	class Bkbm : public IborIndex {
      public:
		  Bkbm(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
              const std::string& p,
              const QuantLib::Handle<QuantLib::YieldTermStructure>& hYTS,
              bool permanent);
    };

	// CAD - Canadian Bills (Bankers Acceptance) index - Canadian dollar offered rate Bills index / CDOR
	// As of 2018, active benchmarks = 1m, 2m, 3m, 6m, 12m
	class Cdor : public IborIndex {
	public:
		Cdor(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			const std::string& p,
			const QuantLib::Handle<QuantLib::YieldTermStructure>& hYTS,
			bool permanent);
	};

	// AUD - Australian Bills index - "bbsw"
	// As of 2018, active benchmarks = 1m, 2m, 3m, 4m, 5m, 6m
	class Bbsw : public IborIndex {
	public:
		Bbsw(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			const std::string& p,
			const QuantLib::Handle<QuantLib::YieldTermStructure>& hYTS,
			bool permanent);
	};

	// JPY - Jpanaese Yen Tibor index - libor like, domestic a/365 index - "Yen Tibor" 
	// NOT EuroYen Tibor - which uses a/360 day count
	// As of 2018, active benchmarks = 1w, 1m, 3m, 6m, 12m
	class Tibor : public IborIndex {
	public:
		Tibor(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			const std::string& p,
			const QuantLib::Handle<QuantLib::YieldTermStructure>& hYTS,
			bool permanent);
	};


	// overnight indexes
	// USD - Federal Funds overnight index
	class FedFunds : public OvernightIndex {
	public:
		FedFunds(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			const QuantLib::Handle<QuantLib::YieldTermStructure>& hYTS,
			bool permanent);
	};

	// NZD - Offical Cash Rate index - OCR
	class Nzocr : public OvernightIndex {
	public:
		Nzocr(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			const QuantLib::Handle<QuantLib::YieldTermStructure>& hYTS,
			bool permanent);
	};

	// AUD - Offical Cash Rate index - OCR
	// It's not called Aonia, except in QuantLib...
	// A much better name would be AuOcr, like the NZ ocr index
	class Aonia : public OvernightIndex {
	public:
		Aonia(const boost::shared_ptr<ObjectHandler::ValueObject>& properties,
			const QuantLib::Handle<QuantLib::YieldTermStructure>& hYTS,
			bool permanent);
	};

}

#endif
