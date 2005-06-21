"""
 Copyright (C) 2005 Eric Ehlers
 Copyright (C) 2005 Plamen Neykov
 Copyright (C) 2005 Aurelien Chanudet

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email quantlib-dev@lists.sf.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
"""

'xml parser'

import common
import xml.dom.minidom
import re
import os

def isEmptyNode(n):
    return n.nodeType == xml.dom.Node.TEXT_NODE \
    and not n.hasChildNodes() \
    and n.nodeValue.strip() == ''

def isTextNode(n):
    return n.nodeType == xml.dom.Node.ELEMENT_NODE \
    and len(n.childNodes) == 1 \
    and n.firstChild.nodeType == xml.dom.Node.TEXT_NODE

def isDictNode(n):
    if n.nodeType != xml.dom.Node.ELEMENT_NODE:
        return False
    for c in n.childNodes:
        if not isTextNode(c) and not isEmptyNode(c):
            return False
    return True

# FIXME should do more elaborate check here
# i.e. 0..n children all with same tag
def isArrayNode(n):
    return n.nodeType == xml.dom.Node.ELEMENT_NODE

def convertNode(n):
    'convert XML node into dict of strings/lists/dicts'
    ret = {}
    if n.attributes:
        ret[common.ATTS] = {}
        for key in n.attributes.keys():
            ret[common.ATTS][key] = n.attributes[key].nodeValue
    for c in n.childNodes:
        if isTextNode(c):
            ret[c.nodeName] = c.firstChild.nodeValue
        elif isDictNode(c):
            ret[c.nodeName] = convertNode(c)
        elif isArrayNode(c):
            ret[c.nodeName] = []
            for cc in c.childNodes:
                if not isEmptyNode(cc):
                    ret[c.nodeName].append(convertNode(cc))
    return ret

def parseFiles(pattern):
    'parse list of xml files into nested data structure'
    ret = {}
    fileNames = os.listdir('.')
    for fileName in fileNames:
        matchName = re.match(pattern, fileName)
        if not matchName: continue
        groupName = matchName.group(1)
        dom = xml.dom.minidom.parse(fileName)
        ret[groupName] = convertNode(dom.documentElement)
    return ret

