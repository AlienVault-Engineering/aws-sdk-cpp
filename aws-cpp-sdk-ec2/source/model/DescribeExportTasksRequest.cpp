﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/ec2/model/DescribeExportTasksRequest.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

using namespace Aws::EC2::Model;
using namespace Aws::Utils;

DescribeExportTasksRequest::DescribeExportTasksRequest() : 
    m_exportTaskIdsHasBeenSet(false),
    m_filtersHasBeenSet(false)
{
}

Aws::String DescribeExportTasksRequest::SerializePayload() const
{
  Aws::StringStream ss;
  ss << "Action=DescribeExportTasks&";
  if(m_exportTaskIdsHasBeenSet)
  {
    unsigned exportTaskIdsCount = 1;
    for(auto& item : m_exportTaskIds)
    {
      ss << "ExportTaskId." << exportTaskIdsCount << "="
          << StringUtils::URLEncode(item.c_str()) << "&";
      exportTaskIdsCount++;
    }
  }

  if(m_filtersHasBeenSet)
  {
    unsigned filtersCount = 1;
    for(auto& item : m_filters)
    {
      item.OutputToStream(ss, "Filter.", filtersCount, "");
      filtersCount++;
    }
  }

  ss << "Version=2016-11-15";
  return ss.str();
}


void  DescribeExportTasksRequest::DumpBodyToUrl(Aws::Http::URI& uri ) const
{
  uri.SetQueryString(SerializePayload());
}
